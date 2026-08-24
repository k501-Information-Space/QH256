#include "qh256.h"

#include <string.h>

static size_t cell_byte_index(size_t cell_index) {
    return cell_index >> 2; /* / 4 */
}

static unsigned cell_shift(size_t cell_index) {
    return (unsigned)((cell_index & 3u) * 2u);
}

static uint8_t cell_mask(size_t cell_index) {
    return (uint8_t)(0x03u << cell_shift(cell_index));
}

void qh256_zero(qh256_t *q) {
    if (q == NULL) {
        return;
    }
    memset(q->bytes, 0, QH256_BYTES);
}

void qh256_init(qh256_t *q) {
    qh256_zero(q);
}

int qh256_valid_cell_index(size_t cell_index) {
    return cell_index < QH256_CELL_COUNT;
}

int qh256_valid_state(qh256_state_t state) {
    return ((unsigned)state) <= ((unsigned)QH256_GUARD);
}

int qh256_set(qh256_t *q, size_t cell_index, qh256_state_t state) {
    size_t byte_index;
    unsigned shift;
    uint8_t mask;

    if (q == NULL || !qh256_valid_cell_index(cell_index) || !qh256_valid_state(state)) {
        return 0;
    }

    byte_index = cell_byte_index(cell_index);
    shift = cell_shift(cell_index);
    mask = cell_mask(cell_index);

    q->bytes[byte_index] = (uint8_t)(q->bytes[byte_index] & (uint8_t)~mask);
    q->bytes[byte_index] = (uint8_t)(q->bytes[byte_index] | (uint8_t)(((unsigned)state & 0x03u) << shift));

    return 1;
}

int qh256_get(const qh256_t *q, size_t cell_index, qh256_state_t *out_state) {
    size_t byte_index;
    unsigned shift;

    if (q == NULL || out_state == NULL || !qh256_valid_cell_index(cell_index)) {
        return 0;
    }

    byte_index = cell_byte_index(cell_index);
    shift = cell_shift(cell_index);

    *out_state = (qh256_state_t)((q->bytes[byte_index] >> shift) & 0x03u);
    return 1;
}

int qh256_equal(const qh256_t *a, const qh256_t *b) {
    if (a == NULL || b == NULL) {
        return 0;
    }
    return memcmp(a->bytes, b->bytes, QH256_BYTES) == 0;
}

void qh256_to_bytes(const qh256_t *q, uint8_t out[QH256_BYTES]) {
    if (q == NULL || out == NULL) {
        return;
    }
    memcpy(out, q->bytes, QH256_BYTES);
}

int qh256_from_bytes(qh256_t *q, const uint8_t in[QH256_BYTES]) {
    if (q == NULL || in == NULL) {
        return 0;
    }
    memcpy(q->bytes, in, QH256_BYTES);
    return 1;
}

int qh256_to_bitstring(const qh256_t *q, char out[QH256_BITSTRING_LEN]) {
    size_t i;
    if (q == NULL || out == NULL) {
        return 0;
    }

    for (i = 0; i < QH256_BITS; ++i) {
        const size_t byte_index = i / 8u;
        const unsigned bit_index = 7u - (unsigned)(i % 8u);
        out[i] = ((q->bytes[byte_index] >> bit_index) & 1u) ? '1' : '0';
    }
    out[QH256_BITS] = '\0';
    return 1;
}

int qh256_from_bitstring(qh256_t *q, const char *bits) {
    size_t i;

    if (q == NULL || bits == NULL) {
        return 0;
    }

    memset(q->bytes, 0, QH256_BYTES);

    for (i = 0; i < QH256_BITS; ++i) {
        const size_t byte_index = i / 8u;
        const unsigned bit_index = 7u - (unsigned)(i % 8u);
        uint8_t value;

        if (bits[i] == '0') {
            value = 0u;
        } else if (bits[i] == '1') {
            value = 1u;
        } else {
            return 0;
        }

        if (value != 0u) {
            q->bytes[byte_index] = (uint8_t)(q->bytes[byte_index] | (uint8_t)(1u << bit_index));
        }
    }

    return bits[QH256_BITS] == '\0';
}

qh256_state_t qh256_merge_state(qh256_state_t a, qh256_state_t b) {
    /*
     * The QH256 merge definition used here is direct bitwise OR on the
     * canonical 2-bit cell encodings.
     */
    return (qh256_state_t)(((unsigned)a & 0x03u) | ((unsigned)b & 0x03u));
}

void qh256_merge(qh256_t *out, const qh256_t *a, const qh256_t *b) {
    size_t i;

    if (out == NULL || a == NULL || b == NULL) {
        return;
    }

    for (i = 0; i < QH256_BYTES; ++i) {
        out->bytes[i] = (uint8_t)(a->bytes[i] | b->bytes[i]);
    }
}

size_t qh256_count_state(const qh256_t *q, qh256_state_t state) {
    size_t i;
    size_t count = 0u;

    if (q == NULL || !qh256_valid_state(state)) {
        return 0u;
    }

    for (i = 0; i < QH256_CELL_COUNT; ++i) {
        qh256_state_t current;
        if (qh256_get(q, i, &current) && current == state) {
            ++count;
        }
    }

    return count;
}

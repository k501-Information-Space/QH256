# QH256 Alpha Mapping

Status: ALPHA / NOT CANONICAL

Structural mapping used only for integration proof:

0 object_present = TRUE for a successfully constructed record
1 readable = record.readable
2 type_regular_file = object_type == 1
3 type_directory = object_type == 2
4 type_symlink = object_type == 3
5 type_other = object_type == 4
6 size_present = record.size_present
7 content_hash_present = record.content_present
8 mtime_present = TRUE
9 mode_present = TRUE
10 path_present = path_len > 0
11 root_present = root_id_len > 0
12 record_valid = TRUE after local record verification
13 object_id_present = TRUE
14 content_observation_available = record.content_present
15 alpha_pipeline_record = TRUE

Cells 16..127 remain UNKNOWN.

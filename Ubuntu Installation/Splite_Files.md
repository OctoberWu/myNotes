
NTFS, exFat or Fat32 are helpless for larger size of files

```console
$split -d -n 2 my_image.tar "my_image.tar.part"
$cat my_image.tar.part* > my_image.tar

// for split command
-a, --suffix-length=N : generate suffixes of length N (default 2)
--additional-suffix=SUFFIX : append an additional SUFFIX to file names.
-b, --bytes=SIZE : put SIZE bytes per output file
-C, --line-bytes=SIZE : put at most SIZE bytes of lines per output file
-d, --numeric-suffixes[=FROM] : use numeric suffixes instead of alphabetic. FROM changes the start value (default 0).
-e, --elide-empty-files : do not generate empty output files with '-n'
--filter=COMMAND : write to shell COMMAND; file name is $FILE
-l, --lines=NUMBER : put NUMBER lines per output file
-n, --number=CHUNKS : generate CHUNKS output files.
-u, --unbuffered : immediately copy input to output with '-n r/...'
```

Note:
* Split may cause some header failed issues.


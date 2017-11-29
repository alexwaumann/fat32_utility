# mfs (in development)

Mav File System (mfs) is a command line utility capable of interpreting a FAT32
file system image.

## Supported Commands

##### open \<filename\>

Opens a FAT32 image (Filenames with spaces).

##### close

Closes the FAT32 image.

##### info

Prints out information about the file system in both hexadecimal and base-10:
  * BPB_BytesPerSec
  * BPB_SecPerClus
  * BPB_RsvdSecCnt
  * BPB_NumFATS
  * BPB_FATSz32

##### state \<filename\> or \<directory name\>

Prints the attributs and starting cluster number of the file or directory name.

##### get \<filename\>

Retrieves a file from the FAT32 image and places it in the current working
directory.

##### cd \<directory\>

Changes the current working directory to the given directory.

##### ls \<directory\>

Lists the directory contents.

##### read \<filename\> \<position\> \<number of bytes\>

Reads from the given file at the position, in bytes, specified by the position
parameter and outputs the number of bytes specified.

##### volume

Prints the volume name of the file system image.

## Building

To build the program on Mac or Linux:

```bash
$ git clone https://github.com/awaumann/fat32_utility.git
$ cd fat32_utility
$ make
$ ./mfs
```

## Authors

  * Alejandro Waumann

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details.
## Swap Size Rearrangement in Ubuntu 18.04

### Quick Start
1. Turn off all swap processes	
```bash
$sudo swapoff -a
```
2. Resize the swap
```bash
$sudo dd if=/dev/zero of=/swapfile bs=1G count=8
// The above command arranges 8G space
$if = input file
$of = output file
$bs = block size
$count = multiplier of blocks
// Make the file usable as swap
$sudo mkswap /swapfile
```
3. Activate the swap file
```bash
$sudo swapon /swapfile
// Check the amount of swap available
$grep SwapTotal /proc/meminfo
```

[ref article](https://bogdancornianu.com/change-swap-size-in-ubuntu/)
# cmoc_os9

Shared CMOC-targeted OS-9 support for projects in this shelf.

This area is intended to hold the smallest reusable layer needed to build
OS-9 binaries with CMOC across multiple nested projects. The initial import
focuses on low-level file I/O helpers and a small header subset that were
proven out while porting `toolshed/tocgen`.

Current layout:

- `include/`: minimal headers needed by CMOC OS-9 ports in this shelf
- `lib/`: low-level OS-9 file I/O and syscall support modules

This is based on the direction of `tlindner/cmoc_os9`, but trimmed to the
pieces that are already building cleanly in this workspace.

{ pkgs }: {
    deps = [
      pkgs.cowsay
      pkgs.clang_12
      pkgs.ccls
      pkgs.gdb
      pkgs.gnumake
    ];
}
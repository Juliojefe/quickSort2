{ pkgs }: {
	deps = [
		pkgs.valgrind-light
  pkgs.qtile
  pkgs.nano
  pkgs.clang_12
		pkgs.ccls
		pkgs.gdb
		pkgs.gnumake
	];
}
{ pkgs }: {
	deps = [
   pkgs.gpp
		pkgs.clang_12
		pkgs.ccls
		pkgs.gdb
		pkgs.gnumake
	];
}
{pkgs, ...}: let
  libPath = with pkgs;
    lib.makeLibraryPath [
      libGL
      libxkbcommon
      wayland
    ];
in
  pkgs.mkShell {
    nativeBuildInputs = with pkgs; [
      cmake
      qt6.full
    ];

    LD_LIBRARY_PATH = libPath;
  }

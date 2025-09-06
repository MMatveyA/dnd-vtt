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
      qt6.qtbase
      qt6.qtquick3d
      qt6.wrapQtAppsHook
    ];

    buildInputs = with pkgs; [
      qt6.qtbase
      qt6.qtquick3d
    ];

    LD_LIBRARY_PATH = libPath;
  }

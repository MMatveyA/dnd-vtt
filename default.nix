{
  self,
  lib,
  pkgs,
  ...
}:
pkgs.stdenv.mkDerivation (finalAttrs: {
  pname = "dnd-vtt";
  version = "0.1";

  src = self;

  doCheck = true;

  nativeBuildInputs = with pkgs; [
    cmake
    qt6.qtbase
    qt6.qtquick3d
    qt6.wrapQtAppsHook
  ];

  buildInputs = with pkgs; [
    qt6.qtbase
    qt6.qtquick3d
    qt6.wrapQtAppsHook
  ];

  installPhase = ''
    mkdir -p $out/bin
    cp src/${finalAttrs.pname} $out/bin
  '';

  meta = {
    description = "DnD Virtual TableTop";
    homepage = "https://github.com/MMatveyA/dnd-vtt";
    mainProgram = "dnd-vtt";
    license = lib.licenses.lgpl3;
    platforms = lib.platforms.linux;
  };
})

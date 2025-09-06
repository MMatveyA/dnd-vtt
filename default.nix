{
  lib,
  pkgs,
  ...
}:
pkgs.stdenv.mkDerivation {
  name = "dnd-vtt";
  src = ./.;

  nativeBuildInputs = with pkgs; [
    cmake
    qt6.full
  ];

  buildInputs = with pkgs; [
    qt6.full
  ];

  meta = with lib; {
    description = "DnD Virtual TableTop";
    homepage = "https://github.com/MMatveyA/dnd-vtt";
    license = licenses.lgpl3;
    platforms = platforms.linux;
  };
}

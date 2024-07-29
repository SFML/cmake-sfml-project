{ pkgs ? import <nixpkgs> {} }:
  pkgs.mkShell {
    nativeBuildInputs = with pkgs.buildPackages; [
      gcc_multi
      cmake
      sfml
      csfml
      libGL
      udev
      openal
      libvorbis
      flac
      xorg.libX11
      xorg.libXrandr
      xorg.libXcursor
      xorg.libXext
      xorg.libXxf86vm
      freetype
    ];
}

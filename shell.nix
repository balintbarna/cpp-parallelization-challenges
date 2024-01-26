{ pkgs ? import <nixpkgs> {} }:

pkgs.mkShell {
  buildInputs = with pkgs; [
    boost
    gcc
    gdb
    git
    gtest
    vscode
  ];
}


{ pkgs ? import <nixpkgs> {} }:

pkgs.mkShell {
  buildInputs = with pkgs; [
    boost
    curl
    gcc
    gdb
    git
    gtest
    vscode
  ];
}


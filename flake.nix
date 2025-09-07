{
  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs/nixos-25.05";
    flake-utils.url = "github:numtide/flake-utils";
  };

  outputs = {
    self,
    nixpkgs,
    flake-utils,
  }:
    flake-utils.lib.eachDefaultSystem (
      system: let
        pkgs = import nixpkgs {inherit system;};
      in {
        apps = {
          dnd-vtt = {
            type = "app";
            program = "${pkgs.lib.getExe self.packages.${system}.default}";
          };
        };

        packages.default = pkgs.callPackage ./default.nix {inherit self;};

        formatter = pkgs.alejandra;

        devShells.default = pkgs.callPackage ./shell.nix {};
      }
    );
}

// swift-tools-version: 5.9
import PackageDescription

let package = Package(
    name: "elements",
    platforms: [
        .macOS(.v13),
        .iOS(.v16),
        .tvOS(.v16)
    ],
    products: [
        .library(
            name: "ElementsCore",
            targets: ["ElementsCore"]
        )
    ],
    targets: [
        .target(
            name: "ElementsCore",
            path: ".",
            exclude: [
                "CMakeLists.txt",
                "Makefile",
                "config.json",
                "README.md",
                "LICENSE",
                "CMakeCache.txt",
                "CMakeFiles",
                "cmake_install.cmake",
                "src/main.cc"
            ],
            sources: [
                "src/elements.cc",
                "src/matrix.cc",
                "src/modules.cc",
                "src/network.cc",
                "src/ranking.cc",
                "src/tree.cc",
                "vendor/json.cc",
                "vendor/wslib.cc"
            ],
            publicHeadersPath: "include",
            cxxSettings: [
                .headerSearchPath("include"),
                .headerSearchPath("vendor")
            ]
        )
    ],
    cxxLanguageStandard: .cxx17
)

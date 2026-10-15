from pybind11.setup_helpers import Pybind11Extension, build_ext
from setuptools import setup

__version__ = "1.0.0"

ext_modules = [
    Pybind11Extension(
        "_elements",
        [
            "src/bindings.cc",
            "src/elements.cc",
            "src/matrix.cc",
            "src/ranking.cc",
            "src/tree.cc",
            "src/modules.cc",
            "src/network.cc",
            "vendor/json.cc",
            "vendor/wslib.cc",
        ],
        include_dirs=["include", "vendor"],
        cxx_std=17,
    ),
]

setup(
    name="elements",
    version=__version__,
    author="William Oliveira de Lagos",
    description="Elements C++ Core Python Bindings",
    ext_modules=ext_modules,
    cmdclass={"build_ext": build_ext},
    zip_safe=False,
    python_requires=">=3.8",
)

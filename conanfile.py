import os
from conan import ConanFile
from conan.tools.cmake import CMake, cmake_layout

class BaseRecipe(ConanFile):
    name = "blockchain"
    version = "1.0"
    
    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeDeps", "CMakeToolchain"

    def requirements(self):
        self.requires(self.tested_reference_str)
        self.requires("app_blockchain/1.0@pasan/testing")

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def layout(self):
        cmake_layout(self)
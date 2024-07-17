from conan import ConanFile


class ExampleRecipe(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeDeps", "CMakeToolchain"

    def requirements(self):
        self.requires("boost/1.85.0")
        self.requires("sqlite3/3.46.0")
        self.requires("jsoncpp/1.9.5")

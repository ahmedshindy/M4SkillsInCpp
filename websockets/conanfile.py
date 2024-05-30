from conans import ConanFile, CMake

class WebSocketppServerConan(ConanFile):
    name = "WebSocketppServer"
    version = "1.0"
    settings = "os", "compiler", "build_type", "arch"
    requires = (
        "websocketpp/0.8.1",
        "asio/1.18.1"
    )
    generators = "cmake"
    default_options = {
        "asio:header_only": True
    }

    def imports(self):
        self.copy("*.dll", dst="bin", src="bin")
        self.copy("*.dylib*", dst="bin", src="lib")
        self.copy("*.so", dst="bin", src="lib")

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

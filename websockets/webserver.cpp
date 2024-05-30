#include <websocketpp/config/asio_no_tls.hpp>
#include <websocketpp/server.hpp>

class MyWebSocketServer {
public:
    MyWebSocketServer() {
        // Set logging settings
        server_.set_access_channels(websocketpp::log::alevel::all);
        server_.clear_access_channels(websocketpp::log::alevel::frame_payload);

        // Initialize Asio
        server_.init_asio();

        // Register our message handler
        server_.set_message_handler(bind(&MyWebSocketServer::on_message,this,::_1,::_2));
    }

    void on_message(websocketpp::connection_hdl hdl, websocketpp::server<websocketpp::config::asio>::message_ptr msg) {
        std::cout << "Received message: " << msg->get_payload() << std::endl;
        // Echo the message back
        server_.send(hdl, msg->get_payload(), msg->get_opcode());
    }

    void run(uint16_t port) {
        // Listen on specified port
        server_.listen(port);

        // Start the server accept loop
        server_.start_accept();

        // Start the ASIO io_service run loop
        server_.run();
    }

private:
    websocketpp::server<websocketpp::config::asio> server_;
};

int main() {
    MyWebSocketServer server;
    server.run(9002);
}
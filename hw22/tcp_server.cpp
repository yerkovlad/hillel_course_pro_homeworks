#include <iostream>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

void startServer(unsigned short port) {
    try {
        boost::asio::io_context io_context;

        tcp::acceptor acceptor(io_context, tcp::endpoint(tcp::v4(), port));
        std::cout << "Server is listening on port " << port << "..." << std::endl;

        while (true) {
            tcp::socket socket(io_context);
            acceptor.accept(socket);

            std::cout << "New client connected: " << socket.remote_endpoint() << std::endl;

            boost::system::error_code error;
            char data[1024];
            size_t length = socket.read_some(boost::asio::buffer(data), error);

            if (!error) {
                std::cout << "Received message: " << std::string(data, length) << std::endl;

                std::string response = "Message received: " + std::string(data, length);
                boost::asio::write(socket, boost::asio::buffer(response), error);
            }

            if (error == boost::asio::error::eof) {
                std::cout << "Client disconnected." << std::endl;
            } else if (error) {
                throw boost::system::system_error(error);
            }
        }
    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

int main() {
    unsigned short port = 8080;
    startServer(port);
    return 0;
}

#include <iostream>
#include <string>
#include <memory>
#include <boost/asio/buffer.hpp>
#include <boost/asio/io_service.hpp>
#include <boost/asio/ip/tcp.hpp>
#include "MenuGenerator.h"

int main()
{
	try
	{
		typedef boost::asio::ip::tcp asiotcp;
		boost::asio::io_service io_service;

		while (true)
		{
			asiotcp::socket socket(io_service);

			asiotcp::acceptor a(io_service, asiotcp::endpoint(asiotcp::v4(), 13));
			a.accept(socket);

			std::array<char, 256> recv_buf;

			std::size_t const received_bytes = socket.receive(
				boost::asio::buffer(recv_buf));

			std::string const inputmessage(recv_buf.data(), received_bytes);
			std::cout << "Client sent message: \"" << inputmessage << "\"" << std::endl;

			std::string str(inputmessage);

			int n = std::stoi(str);

			std::string const message = MenuGenerator::MenuItemSelected(n)  +"\n";
			socket.send(boost::asio::buffer(message));
		}
	}
	catch (std::exception const &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}


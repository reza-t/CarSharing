// Server.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/lexical_cast.hpp>
#include <iostream>
#include <vector>
#include "Connection.h" // Must come before boost/serialization headers.
#include <boost/serialization/vector.hpp>
#include "User.h"
#include "Car.h"
#include "ManageUser.h"
//#include "MainMenu.h"

/// Serves stock quote information to any client that connects to it.
class Server
{
public:
	/// Constructor opens the acceptor and starts waiting for the first incoming
	/// connection.
	Server(boost::asio::io_service& io_service, unsigned short port);
	/// Handle completion of a accept operation.
	void handle_accept(const boost::system::error_code& e, connection_ptr conn);

	void handle_read(const boost::system::error_code& e, connection_ptr conn);
	/// Handle completion of a write operation.
	void handle_write(const boost::system::error_code& e, connection_ptr conn);
	void handle_rec(const boost::system::error_code& e, connection_ptr conn);
private:
	/// The acceptor object used to accept incoming socket connections.
	boost::asio::ip::tcp::acceptor acceptor_;

	/// The data to be sent to each client.
	std::vector<User> users_;
	std::vector<Car> car_;
	//std::vector<string> menu_;
	char option_;
	User user_;
	ManageUser manageUser;
	//MainMenu mainMenu_;
};

// TODO: Reference additional headers your program requires here.

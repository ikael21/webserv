//
// Created by Retro Joella on 11/14/21.
//

#ifndef WEBSERV_MAININCLUDES_HPP
# define WEBSERV_MAININCLUDES_HPP

#include <vector>
#include <map>
#include <string>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <fstream>
#include <cstdint>
#include <arpa/inet.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/select.h>
#include <sys/time.h>
#include <sys/stat.h>
#include <sstream>
#include <ctime>
#include <unistd.h>

#include "Location.hpp"
#include "SettingsServer.hpp"
#include "Request.hpp"
#include "Response.hpp"
#include "Server.hpp"
#include "Client.hpp"
#include "Cgi.hpp"

//colors for beauty
#define YELLOW		"\033[33;1m"
#define RESET		"\033[0m"
#define RED			"\033[31;1m"
#define GREEN		"\033[32;1m"
#define MAGENTA		"\033[35;1m"
#define BLUE		"\033[34;1m"

#define DEBUG		0

namespace ikael {
	static bool	isCharWhiteSpace(unsigned char c) {
		return std::isspace(c);
	}
}

typedef enum	fileType
{
	DDIR  = 0,
	FFILE  = 1,
	NONEXIST = -1
}	t_fileType;

typedef struct s_fileInfo
{
	long long int	fLength;
	t_fileType		fType;
	string			fExtension;
	int				fStatus;
}		t_fileInfo;

/*
	end of start line
	or header fields
	or request at all
*/
#define CR				"\r"
#define LF				"\n"
#define CRLF			"\r\n"


//#include "ParseFile.hpp"
int				startParser(char *fileName, std::vector<t_server> &servers);
void			printLocations(std::map<std::string, Location> locations);
void			printServ(t_server serv);
void			Start(vector<Server*> Servers);
std::string		ft_itoa(int x);
void 			free_execData(const char ***execData);
bool			urlInfo(string fPath,t_fileInfo *fStruct, std::ifstream &FILE);
const char		***makeData_for_exec(std::string &path, std::map <std::string, std::string> &headers);
char			*gen_def_page(int statusCode, uint64_t &bodySize);
std::time_t		increase_session_time();
std::map <int, std::string> &error_map();

#endif //WEBSERV_MAININCLUDES_HPP

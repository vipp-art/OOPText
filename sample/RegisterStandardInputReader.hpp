#pragma once
#include <iostream>
#include <string>
#include"BaseRegisterReader.hpp"


/** •W€“ü—Í‚©‚çî•ñ‚ğæ“¾‚·‚é */
class RegisterStandardInputReader : public BaseRegisterReader {

public:
	/** */
	virtual ~RegisterStandardInputReader() {}
	
	/** “Ç‚İ‚İ */
	virtual void read() {
		int64 id;
		std::string title;

		std::cout << "‘ ‘‚Ì“o˜^‚ğ‚µ‚Ü‚·B" << std::endl;

		std::cout << "‘ ‘”Ô†‚ğ“ü—Í:" << std::flush;
		std::cin >> id;
		std::cout << std::endl;

		std::cout << "‘è–¼‚ğ“ü—Í:" << std::flush;
		std::cin >> title;
		std::cout << std::endl;
		
		this->id( id );
		this->title( title );
	}

};

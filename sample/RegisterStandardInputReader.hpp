#pragma once
#include <iostream>
#include <string>
#include"BaseRegisterReader.hpp"


/** �W�����͂�������擾���� */
class RegisterStandardInputReader : public BaseRegisterReader {

public:
	/** */
	virtual ~RegisterStandardInputReader() {}
	
	/** �ǂݍ��� */
	virtual void read() {
		int64 id;
		std::string title;

		std::cout << "�����̓o�^�����܂��B" << std::endl;

		std::cout << "�����ԍ������:" << std::flush;
		std::cin >> id;
		std::cout << std::endl;

		std::cout << "�薼�����:" << std::flush;
		std::cin >> title;
		std::cout << std::endl;
		
		this->id( id );
		this->title( title );
	}

};

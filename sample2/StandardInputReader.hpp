#pragma once
#include <iostream>
#include <string>
#include"IReader.hpp"


/** �W�����͂�������擾���� */
class StandardInputReader : public IReader {

public:
	/** */
	virtual ~StandardInputReader() {}
	
	/** ���O�ǂݍ��� */
	virtual void read()
	{
		std::cout << "�W�����͂��瑠����o�^���܂��B" << std::endl;
	}
	
	/** �w��̃^�O��64�r�b�g�����Ŏ擾 */
	virtual int64 getInt64( std::string tag )
	{
		return std::stoll( getText( tag ) );
	}

	/** �w��̃^�O�𕶎���Ŏ擾 */
	virtual std::string getText( std::string tag )
	{
		std::string result;
		std::cout << tag << ':' << std::flush;
		std::cin >> result;
		return result;
	}

};

#include "Book.hpp"
#include "BookDatabase.hpp"
#include "BookRegister.hpp"
#include "RegisterStandardInputReader.hpp"
#include "RegisterIniFileReader.hpp"

int main()
{
	// �����Ǘ��pDB�p��
	BookDatabase database;
	
	// �����o�^�p�V�X�e���p��
	BookRegister reg( &database );
	
	// �f�[�^�̓��͕��@��p��
	RegisterStandardInputReader stdreader;					// �W�����͂���ǂݍ���
	RegisterIniFileReader fileReader( "data/book.ini" );	// ini�t�@�C������ǂݍ���
	
	// �o�^
	reg.doRegister( &fileReader );
	reg.doRegister( &stdreader );
	
	// �o�^���ꂽ������\��
	database.printAll();
	
	return 0;
}

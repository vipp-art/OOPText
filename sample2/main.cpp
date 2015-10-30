#include "Book.hpp"
#include "BookDatabase.hpp"
#include "BookRegister.hpp"
#include "StandardInputReader.hpp"
#include "IniFileReader.hpp"

int main()
{
	// �����Ǘ��pDB�p��
	BookDatabase database;
	
	// �����o�^�p�V�X�e���p��
	BookRegister reg( &database );
	
	// �f�[�^�̓��͕��@��p��
	StandardInputReader stdreader;					// �W�����͂���ǂݍ���
	IniFileReader fileReader( "data/book.ini" );	// ini�t�@�C������ǂݍ���
	
	// �o�^
	reg.doRegister( &fileReader );
	reg.doRegister( &stdreader );
	
	// �o�^���ꂽ������\��
	database.printAll();
	
	return 0;
}

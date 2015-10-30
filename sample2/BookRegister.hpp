#pragma once
#include "BookDatabase.hpp"
#include "IReader.hpp"

/** �����̏���DB�ɓo�^����N���X */
class BookRegister {
private:
	/** �o�^�Ώۂ�DB */
	BookDatabase* target_;
	
public:
	/**
	 * �o�^����w�肵�ď�����
	 * @param target �o�^��
	 */
	BookRegister( BookDatabase* target )
		: target_( target )
	{
	}

	/**
	 * �o�^
	 * @param input �f�[�^�̓���
	 */
	void doRegister( IReader* input )
	{
		input->read();
		
		int64 id = input->getInt64( "id" );
		std::string title = input->getText( "title" );
		
		Book book( id, title );
		target_->add( book );
	}
};

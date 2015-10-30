#pragma once
#include "BookDatabase.hpp"
#include "BaseRegisterReader.hpp"

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
	void doRegister( BaseRegisterReader* input )
	{
		input->read();
		
		int64 id = input->id();
		std::string title = input->title();
		
		Book book( id, title );
		target_->add( book );
	}
};

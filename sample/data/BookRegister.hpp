#pragma once
#include "BookDatabase.hpp"
#include "BaseRegisterReader.hpp"

/** ‘ ‘‚Ìî•ñ‚ðDB‚É“o˜^‚·‚éƒNƒ‰ƒX */
class BookRegister {
private:
	/** “o˜^‘ÎÛ‚ÌDB */
	BookDatabase* target_;
	
public:
	/**
	 * “o˜^æ‚ðŽw’è‚µ‚Ä‰Šú‰»
	 * @param target “o˜^æ
	 */
	BookRegister( BookDatabase* target )
		: target_( target )
	{
	}

	/**
	 * “o˜^
	 * @param input ƒf[ƒ^‚Ì“ü—Í
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

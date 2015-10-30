#pragma once
#include "BookDatabase.hpp"
#include "IReader.hpp"

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
	void doRegister( IReader* input )
	{
		input->read();
		
		int64 id = input->getInt64( "id" );
		std::string title = input->getText( "title" );
		
		Book book( id, title );
		target_->add( book );
	}
};

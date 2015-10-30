#pragma once
#include <string>
#include "Types.h"

/** �o�^����ۂ̏��̎擾�V�X�e���̊�� */
class IReader
{
public:
	virtual void read() =0;
	
	/** �w��̃^�O��64�r�b�g�����Ŏ擾 */
	virtual int64 getInt64( std::string tag ) =0;

	/** �w��̃^�O�𕶎���Ŏ擾 */
	virtual std::string getText( std::string tag ) =0;
	
protected:
	
	/** �p����p */
	IReader() {}
	
	/** �p����p */
	virtual ~IReader() {}
};

#pragma once
#include <string>
#include "Types.h"

/** �o�^����ۂ̏��̎擾�V�X�e���̊�� */
class BaseRegisterReader
{
private:
	/** �����ԍ� */
	int64 id_;
	
	/** �薼 */
	std::string title_;
	
public:
	/** �ǂݍ��ޏ��� */
	virtual void read() =0;
	
	/** �����ԍ��̎擾 */
	int64 id() const { return id_; }
	
	/** �薼�̎擾 */
	const std::string& title() const { return title_; }
	
protected:
	
	/** �p����p */
	BaseRegisterReader() {}
	
	/** �p����p */
	virtual ~BaseRegisterReader() {}
	
	/** �p����p�F�����ԍ��̐ݒ� */
	void id( int64 id )
	{
		id_ = id;
	}
	
	/** �p����p�F�薼��ݒ� */
	void title( const std::string& title )
	{
		title_ = title;
	}
};

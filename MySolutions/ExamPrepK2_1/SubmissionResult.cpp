#include "SubmissionResult.h"

SubmissionResult::SubmissionResult(std::string codeName) : codeName_(std::move(codeName)), success_(true)
{
}

SubmissionResult::SubmissionResult(std::vector<std::string> errors) : errors_(std::move(errors)), success_(false)
{
}

const std::string& SubmissionResult::getCodeName() const
{
	return this->codeName_;
}

const std::vector<std::string>& SubmissionResult::getErrors() const
{
	return this->errors_;
}

bool SubmissionResult::isSuccess() const
{
	return this->success_;
}

SubmissionResult::operator bool() const
{
	return this->isSuccess();
}
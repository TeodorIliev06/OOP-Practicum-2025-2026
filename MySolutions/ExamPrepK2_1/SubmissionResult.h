#pragma once
#include <vector>
#include <iostream>
class SubmissionResult {
	std::string codeName_;
	std::vector<std::string> errors_;
	bool success_;

public:
	explicit SubmissionResult(std::string codeName);
	explicit SubmissionResult(std::vector<std::string> errors);

	const std::string& getCodeName() const;
	const std::vector<std::string>& getErrors() const;
	bool isSuccess() const;

	explicit operator bool() const;
};
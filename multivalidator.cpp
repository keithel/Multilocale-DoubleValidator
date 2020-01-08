#include "multivalidator.h"

MultiValidator::MultiValidator(QObject *parent)
    : QValidator(parent)
{
}

QValidator::State MultiValidator::validate(QString &input, int &pos) const
{
    QValidator::State state = QValidator::Invalid;
    for (auto validator : mValidators)
    {
        state = validator->validate(input, pos);
        if (state == QValidator::Acceptable)
            break;
    }
    return state;
}

void MultiValidator::addValidator(QValidator *validator)
{
    mValidators.append(validator);
}

void MultiValidator::clearValidators()
{
    mValidators.clear();
}

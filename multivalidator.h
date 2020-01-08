#ifndef MULTIVALIDATOR_H
#define MULTIVALIDATOR_H

#include <QList>
#include <QValidator>

class MultiValidator : public QValidator
{
public:
    MultiValidator(QObject *parent = nullptr);

    void addValidator(QValidator* validator);
    void clearValidators();

    QValidator::State validate(QString &input, int &pos) const override;


protected:
    QList<QValidator*> mValidators;
};

#endif // MULTIVALIDATOR_H

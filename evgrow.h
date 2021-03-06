#ifndef EVGROW_H
#define EVGROW_H

#include <QWidget>
#include <QLabel>
#include <QDoubleSpinBox>
#include <QHBoxLayout>
#include <QVBoxLayout>

enum TypeState {
    TypeStateUndefined = -1,
    TypeStateUnstable,
    TypeStateMiddle,
    TypeStateStable
};

class EvgRow : public QWidget
{
    Q_OBJECT
public:
    explicit EvgRow(QWidget *parent = 0);
    ~EvgRow();

    // Section for initialize rows;
    virtual void init();
    void createSpinBox();
    virtual void settingLayout();

    // Getters and Setters below;
    void setIdText(int newId);
    virtual void changeIdToText(QString &);
    virtual void setStringByState(TypeState state);
    void setTextDefinition(QString newText);
    double getValue() const;
    void setValue(float value);

    void setEditable(bool yes = TRUE);

    QLabel *labelId();
    QDoubleSpinBox *spinBoxRow();
    QLabel *labelDefinition();

protected:
    QLabel *pIdCoefficient;
    QDoubleSpinBox *pCoefficientValue;
    QLabel *pDefinitionCoefficient;
};

#endif // EVGROW_H

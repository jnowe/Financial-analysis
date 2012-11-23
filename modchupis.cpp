#include "modchupis.h"

modChupis::modChupis(QWidget *parent) :
    EvgBasicModel(CountChupis,
                  parent,
                  tr("qrc:/models/chupis"),
                  tr("Модель Чупіса"),
                  tr("Z =-1,3496-0,6183Х1+0,6867К2"))
{
}

void modChupis::setRowsDefinitions()
{
    pCoefficientRows[0].setTextDefinition(tr("ф.1, р. 260 / ф.1, р. 620 – коефіцієнт загальної ліквідності;"));
    pCoefficientRows[1].setTextDefinition(tr("(ф.1, р. 480+620) / ф.1, р. 640 – коефіцієнт фінансової залежності."));
}

void modChupis::calculate(EvgBasicModel *pInputData)
{
    // 2/8
    if (pInputData->getValue(7))
        pCoefficientRows[0].setValue(pInputData->getValue(1)/pInputData->getValue(7));

    // (7+8)/9
    if (pInputData->getValue(8))
        pCoefficientRows[1].setValue((pInputData->getValue(6)+pInputData->getValue(7))/pInputData->getValue(8));

    if (checkForZeros())
        result = -1.3496f - 0.6183f*pCoefficientRows[0].getValue()\
                + 0.6867f*pCoefficientRows[1].getValue();
    else
        result = 0.0f;
}
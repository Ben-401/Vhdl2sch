#include "input.h"

input::input()
{
    lenght = 1.2;
    type = WIRE;
    size = 1;
}

input::input(QString name) {

    this->ioLabel = name;

}



void input::setSentence()
{
    if (type == BUS) {
        ioSentence = QString("\\node[right] (") + ioLabel + QString(") at (")
                + QString::number(posx,'g',4) + QString(",") + QString::number(posy,'g',4)
                + QString(") {") + ioLabel +QString("};\n");
        ioSentence += "\\draw[bus={" + size + "}] (" + QString::number(posx-lenght,'g',4) + ","
                    + QString::number(posy,'g',4) + ") -- (" + ioLabel  + ");\n";
    }
    if (type == WIRE) {
        ioSentence = QString("\\node[right] (") + ioLabel + QString(") at (")
                + QString::number(posx,'g',4) + QString(",") + QString::number(posy,'g',4)
                + QString(") {") + ioLabel +QString("};\n");
        ioSentence += QString("\\draw[wire] (") + QString::number(posx-lenght,'g',4) +","
                    + QString::number(posy,'g',4) + ") -- (" + ioLabel  + ");\n";
    }

    if (type == CLK) {
        ioSentence = QString("\\node[right] (") + ioLabel + QString(") at (")
                + QString::number(posx,'g',4) + QString(",") + QString::number(posy,'g',4)
                + QString(") {") + "  " + ioLabel +QString("};\n");
        ioSentence += QString("\\draw[ckwire] (") + QString::number(posx-lenght,'g',4) +","
                    + QString::number(posy,'g',4) + ") -- (" + ioLabel  + ");";
    }
}

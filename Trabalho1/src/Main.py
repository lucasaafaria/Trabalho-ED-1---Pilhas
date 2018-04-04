from subprocess import Popen, PIPE
import sys
import functools

from PyQt5.QtWidgets import QMainWindow, QApplication, QGridLayout, QWidget, QPushButton, QLineEdit


class Principal(QWidget):

    def __init__(self):
        super(Principal, self).__init__()
        self.texto = QLineEdit(self)
        self.resultado = QLineEdit(self)
        self.resultado.setDisabled(True)

        self.initUI()

    def initUI(self):

        grid = QGridLayout()
        self.setLayout(grid)
        grid.addWidget(self.texto, 0, 0, 1, 4)
        grid.addWidget(self.resultado, 1, 0, 2, 4)
        names = ['Cls', 'Bck', '', '/',
                 '7', '8', '9', '*',
                 '4', '5', '6', '-',
                 '1', '2', '3', '+',
                 '0', '(', ')', '=']

        positions = [(i, j) for i in range(3, 8) for j in range(4)]

        for position, name in zip(positions, names):

            if name == '':
                continue
            button = QPushButton(name)
            if name == 'Cls':
                button.clicked.connect(self.texto.clear)
            elif name == 'Bck':
                button.clicked.connect(self.texto.backspace)
            elif name == '=':
                button.clicked.connect(self.calcular)
            else:
                button.clicked.connect(functools.partial(self.adicionar, name))

            grid.addWidget(button, *position)

        self.move(300, 150)
        self.setWindowTitle('Calculator')
        self.show()

    def calcular(self):
        comando = self.texto.text()
        self.texto.clear()
        p = Popen(["./a.out"], stdout=PIPE, stdin=PIPE, universal_newlines=True)
        (output, err) = p.communicate(comando+'\n')
        self.resultado.clear()
        self.resultado.insert('=')
        self.resultado.insert(output)
        self.resultado.insert(err)

    def adicionar(self, char):
        self.texto.insert(str(char))


if __name__ == '__main__':
    app = QApplication(sys.argv)
    principal = Principal()
    sys.exit(app.exec_())
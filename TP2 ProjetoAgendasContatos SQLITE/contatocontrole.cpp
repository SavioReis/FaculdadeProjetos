#include "contatocontrole.h"

namespace srlg {

ContatoControle::ContatoControle() {
    contatoPersistencia = new ContatoPersistencia();
}

ContatoControle::~ContatoControle() {
    delete contatoPersistencia;
}

void ContatoControle::verificarCPF(const Contato& objContato) const {
    QString cpf = objContato.getCpf();

    if (cpf.isEmpty()) {
        throw QString("ERRO: CPF necessita ser preenchido. Insira um CPF.");
    }

    if (cpf.length() != 11) {
        throw QString("ERRO: CPF precisa ter 11 dígitos.");
    }

    if (contatoPersistencia->consultar(cpf)) {
        throw QString("ERRO: CPF duplicado.");
    }

    int soma = 0;
    for (int i = 0; i < 9; ++i) {
        soma += cpf.at(i).digitValue() * (10 - i);
    }

    int digitoVerificador1 = (soma * 10) % 11;
    if (digitoVerificador1 == 10) {
        digitoVerificador1 = 0;
    }

    if (digitoVerificador1 != cpf.at(9).digitValue()) {
        throw QString("ERRO: O primeiro dígito verificador está inválido.");
    }

    soma = 0;
    for (int i = 0; i < 10; ++i) {
        soma += cpf.at(i).digitValue() * (11 - i);
    }

    int digitoVerificador2 = (soma * 10) % 11;
    if (digitoVerificador2 == 10) {
        digitoVerificador2 = 0;
    }

    if (digitoVerificador2 != cpf.at(10).digitValue()) {
        throw QString("ERRO: O segundo dígito verificador está inválido.");
    }
}

void ContatoControle::verificarRegrasIncluir(const Contato& objContato) const {
    if (objContato.getNome().isEmpty()) {
        throw QString("ERRO: Nome completo necessita ser preenchido. Insira um nome.");
    }

    if (objContato.getEmail().isEmpty()) {
        throw QString("ERRO: Email necessita ser preenchido. Insira um email.");
    }

    int arrobaDigito = objContato.getEmail().indexOf("@");
    int pontoDigito = objContato.getEmail().indexOf(".");

    if (arrobaDigito == -1) {
        throw QString("O seu email precisa de um @.");
    }

    if (pontoDigito == -1) {
        throw QString("O seu email precisa de um ponto.");
    }

    if (pontoDigito < arrobaDigito) {
        throw QString("ERRO: O email não está no formato correto. Verifique se escreveu seu email corretamente.");
    }

    QString domain = objContato.getEmail().mid(arrobaDigito + 1, pontoDigito - arrobaDigito - 1);
    QString afterDot = objContato.getEmail().mid(pontoDigito + 1);

    if (domain.isEmpty() || afterDot.isEmpty()) {
        throw QString("É necessário escrever após o ponto.");
    }

    for (const QChar& c : domain + afterDot) {
        if (!c.isLetter() && c != '.') {
            throw QString("Um email escrito dessa forma após o @ é inválido.");
        }
    }

    if (objContato.getEmail().lastIndexOf(".") < objContato.getEmail().indexOf("@")) {
        throw QString("ERRO: Não existe um email sem nenhum ponto após o @.");
    }

    if (objContato.getEndereco().getLogradouro().isEmpty()) {
        throw QString("ERRO: Preencha o campo do logradouro.");
    }

    if (objContato.getEndereco().getNumero().isEmpty()) {
        throw QString("ERRO: Preencha o campo do número da casa.");
    }

    if (QString::number(objContato.getEndereco().getCep()).isEmpty()) {
        throw QString("ERRO: Preencha o campo do CEP.");
    }

    if (QString::number(objContato.getFone().getDdi()).isEmpty()) {
        throw QString("ERRO: O DDI precisa ser inserido.");
    }

    if (QString::number(objContato.getFone().getDdi()).length() != 2) {
        throw QString("ERRO: O DDI precisa ter 2 dígitos.");
    }

    if (QString::number(objContato.getFone().getDdd()).isEmpty()) {
        throw QString("ERRO: O DDD precisa ser inserido.");
    }

    if (QString::number(objContato.getFone().getDdd()).length() != 2) {
        throw QString("ERRO: O DDD precisa ter 2 dígitos.");
    }

    if (QString::number(objContato.getFone().getNumero()).isEmpty()) {
        throw QString("ERRO: O número precisa ser inserido.");
    }

    if (QString::number(objContato.getFone().getNumero()).length() != 9) {
        throw QString("ERRO: O número precisa ter 9 dígitos.");
    }
}

void ContatoControle::incluir(const Contato& objContato) const {
    try {
        verificarRegrasIncluir(objContato);
        verificarCPF(objContato);
        contatoPersistencia->incluir(objContato);
    } catch (const QString& erro) {
        throw erro;
    }
}

std::list<Contato>* ContatoControle::getListaDeContatos() const {
    return contatoPersistencia->getListaDeContatos();
}

Contato *ContatoControle::consultar (QString &cpf) const{
    return contatoPersistencia->consultar(cpf);
}
void ContatoControle::excluir(QString cpf) const{
    if(contatoPersistencia->consultar(cpf)==0) throw QString ("O CPF não existe.");
            contatoPersistencia->excluir(cpf);
}

void ContatoControle::alterar(const Contato& objContato) const {
    verificarRegrasIncluir(objContato);
    contatoPersistencia->alterar(objContato);
}

}  // namespace srlg

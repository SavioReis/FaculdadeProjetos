#include "contatocontrole.h"
namespace srlg{
ContatoControle::ContatoControle():
    contatoPersistencia(0)
{
    contatoPersistencia = new ContatoPersistencia();
}
void ContatoControle::verificarCPF(const Contato &objContato) const{
    if(objContato.getCpf().isEmpty()) throw QString ("ERRO: Não deixe em Branco o CPF");
    if(objContato.getCpf().length() != 11) throw QString ("ERRO: CPF precisa ter 11 dígitos.");
            if(objContato.getCpf().length() == 11){
            QString cpfAux = objContato.getCpf();
            if(contatoPersistencia->consultar(cpfAux)) throw QString ("ERRO: CPF duplicado.");
        }
    if(objContato.getCpf().length() == 11){
        int soma = 0;
        for (int i = 0; i < 9; ++i) {
            soma += (objContato.getCpf().at(i).digitValue()) * (10 - i);
        }
        int digitoVerificador1 = (soma * 10) % 11;
        if (digitoVerificador1 == 10)
            digitoVerificador1 = 0;
        // Verifica o primeiro dígito verificador
        if (digitoVerificador1 != objContato.getCpf().at(9).digitValue()) throw QString ("O primeiro digito verificador está invalido");
                // Calcula o segundo dígito verificador
                soma = 0;
        for (int i = 0; i < 10; ++i) {
            soma += (objContato.getCpf().at(i).digitValue()) * (11 - i);
        }
        int digitoVerificador2 = (soma * 10) % 11;
        if (digitoVerificador2 == 10)
            digitoVerificador2 = 0;
        // Verifica o segundo dígito verificador
        if (digitoVerificador2 != objContato.getCpf().at(10).digitValue()) throw QString ("O segundo digito verificador está invalido");
    }
}

void ContatoControle::verificarRegrasIncluir(const Contato &objContato) const{
    if(objContato.getNome().isEmpty()) throw QString ("ERRO: Não deixe em Branco o epaço de nome");
    if(objContato.getEmail().isEmpty()) throw QString ("ERRO: Não deixe em Branco o email");
      int arrobaDigito = objContato.getEmail().indexOf("@");
      int pontoDigito = objContato.getEmail().indexOf(".");
      if (arrobaDigito == -1) throw QString ("O seu email precisa de um @");
      if (pontoDigito == -1) throw QString ("O seu email precisa de um ponto.");
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
                     throw QString("O email escrito dessa forma após o @ é inválido");
                 }
         }
    if(objContato.getEmail().lastIndexOf(".") < objContato.getEmail().indexOf("@")) throw QString ("ERRO: Precisa de um . depois do @ , exemplo @.");
    if(objContato.getEndereco().getLogradouro().isEmpty()) throw QString ("ERRO: Não deixe em Branco o logradouro.");
    if((objContato.getEndereco().getNumero()).isEmpty()) throw QString ("ERRO: Não deixe em Branco o número de casa");
    if(QString::number(objContato.getEndereco().getCep()).isEmpty()) throw QString ("ERRO: Não deixe em Branco o CEP");
    if(QString::number(objContato.getFone().getDdi()).isEmpty()) throw QString ("ERRO: Não deixe em Branco o DDI");
    if(QString::number(objContato.getFone().getDdi()).length() != 2) throw QString ("ERRO: O DDI precisa ter 2 dígitos.");
    if(QString::number(objContato.getFone().getDdd()).isEmpty()) throw QString ("ERRO: O DDD  precisa ser inserido.");
    if(QString::number(objContato.getFone().getDdd()).length() != 2) throw QString ("ERRO: O DDD precisa ter 2 dígitos.");
    if(QString::number(objContato.getFone().getNumero()).isEmpty()) throw QString ("ERRO: O DDD  precisa ser inserido.");
    if(QString::number(objContato.getFone().getNumero()).length() != 9) throw QString ("ERRO: O número precisa ter 9 dígitos.");
    return;
}

void ContatoControle::criarArquivo()const{
    contatoPersistencia->criarArquivo();
}
void ContatoControle::incluir (const Contato &objContato) const{
    try {
        criarArquivo();
        verificarRegrasIncluir(objContato);
        verificarCPF(objContato);
        contatoPersistencia->incluir(objContato);
        return;
    } catch (QString &erro) {
        throw erro;
    }
    return;
}
std::list<Contato> *ContatoControle::getListaDeContatos()const {
    return contatoPersistencia->getListaDeContatos();
}

Contato *ContatoControle::consultar (QString &cpf) const{
    return contatoPersistencia->consultar(cpf);
}
void ContatoControle::excluir(QString cpf) const{
    if(contatoPersistencia->consultar(cpf)==0) throw QString ("O CPF não existe.");
    contatoPersistencia->excluir(cpf);
}
void ContatoControle::alterar(const Contato &objContato) const{
    verificarRegrasIncluir(objContato);
    contatoPersistencia->alterar(objContato);
}

}

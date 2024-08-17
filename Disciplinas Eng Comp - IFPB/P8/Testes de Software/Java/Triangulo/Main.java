public class Main {
    public static void main(String[] args) {
        Livro livro = new Livro("Meu Livro", 2025, "Eu Mesmo", "1234567890");
        boolean lancamento = livro.verificaLancamento();
        System.out.println("É um lançamento recente? " + lancamento);
    }
}
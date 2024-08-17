/*
import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

public class BibliotecaTest {

    @Test
    public void testPatrimonioHistorico_true() {
        // Criando uma biblioteca fundada antes de 1980
        Biblioteca biblioteca = new Biblioteca("Biblioteca Antiga", "00.000.000/0001-00", 1975);

        // Verificando se o metodo patrimonioHistorico retorna true
        assertTrue(biblioteca.patrimonioHistorico());
    }

    @Test
    public void testPatrimonioHistorico_false() {
        // Criando uma biblioteca fundada em 1980 ou depois
        Biblioteca biblioteca = new Biblioteca("Biblioteca Moderna", "11.111.111/1111-11", 1990);

        // Verificando se o metodo patrimonioHistorico retorna false
        assertFalse(biblioteca.patrimonioHistorico());
    }

    @Test
    public void testGettersAndSetters() {
        // Criando uma instância da classe Biblioteca
        Biblioteca biblioteca = new Biblioteca("Biblioteca Teste", "22.222.222/2222-22", 2000);

        // Testando os métodos setters e getters
        biblioteca.setNome("Nova Biblioteca");
        biblioteca.setCnpj("33.333.333/3333-33");
        biblioteca.setAnoFundacao(1985);

        assertEquals("Nova Biblioteca", biblioteca.getNome());
        assertEquals("33.333.333/3333-33", biblioteca.getCnpj());
        assertEquals(1985, biblioteca.getAnoFundacao());
    }
}
*/


import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

public class BibliotecaTest {

    @Test
    void testAdicionarLivro() {
        Biblioteca biblioteca = new Biblioteca("Biblioteca Teste", 2000);
        Livro livro = new Livro("Livro Teste", 2010);
        biblioteca.adicionarLivro(livro);
        assertEquals(1, biblioteca.quantidadeLivros());
    }

    @Test
    void testPatrimonioHistorico() {
        Biblioteca biblioteca = new Biblioteca("Biblioteca Teste", 1940);
        assertTrue(biblioteca.patrimonioHistorico());
    }

    @Test
    void testNaoPatrimonioHistorico() {
        Biblioteca biblioteca = new Biblioteca("Biblioteca Teste", 2000);
        assertFalse(biblioteca.patrimonioHistorico());
    }
}
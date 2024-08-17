public class VeiculoTest {
    @Test
    public void testCalculaGarantia() {
        Veiculo veiculo = new Veiculo("ABC123", "PICKUP", 2020);

        assertEquals(2025, veiculo.calculaGarantia());
    }
}
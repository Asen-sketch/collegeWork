package lab5question;

import java.util.HashMap;
import java.util.LinkedList;
import java.util.Map;

public class StockTicker {
    private Map<String, LinkedList<Integer>> stockPrices;

    public StockTicker() {
        stockPrices = new HashMap<>();
    }

    public void updatePrice(String stockSymbol, int price) {
        stockPrices.putIfAbsent(stockSymbol, new LinkedList<>());
        stockPrices.get(stockSymbol).add(price);
    }

    public Integer getLastPrice(String stockSymbol) {
        LinkedList<Integer> prices = stockPrices.get(stockSymbol);
        if (prices == null || prices.isEmpty()) {
            System.out.println("no info on " + stockSymbol);
            return null;
        }
        return prices.getLast();
    }

    public static void main(String[] args) {
        var ticker = new StockTicker();
        ticker.updatePrice("AAPL", 150);
        ticker.getLastPrice("AAPL");
        System.out.println(ticker.stockPrices);
    }
}


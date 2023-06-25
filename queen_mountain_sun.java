import java.util.HashMap;
import java.util.Map;

public class LocalBusinessDevelopment {

    /**
     * This class is designed to promote local businesses,
     * helping them to become an integral part of the community.
     */
    public static void main (String[] args) {

        // create a new hashmap that will store the local businesses
        Map<String, Double> localBusinesses = new HashMap<>();

        // put the names of the businesses and their respective profits in the map
        localBusinesses.put("Bakery", 845.10);
        localBusinesses.put("Butcher", 912.45);
        localBusinesses.put("Fishmonger", 753.20);
        localBusinesses.put("Post Office", 721.67);
        localBusinesses.put("Hardware Store", 618.11);
        localBusinesses.put("Greengrocer", 903.30);

        // calculate the total profits made by the local businesses
        double totalProfits = 0.0;
        for (String businessName : localBusinesses.keySet()) {
            totalProfits += localBusinesses.get(businessName);
        }

        // calculate the average profits made by the local businesses
        double avgProfits = totalProfits / localBusinesses.size(); 
          
        // print the profits for each local business
        System.out.println("Profits made by local businesses:");
        for (String businessName : localBusinesses.keySet()) {
            System.out.println(businessName + ": " + localBusinesses.get(businessName));
        }
        
        // print the total profits
        System.out.println("Total profits of local businesses: " + totalProfits);

        // print the average profits
        System.out.println("Average profits of local businesses: " + avgProfits);

        // create a variable that will track the total number of jobs created by the local businesses
        int totalJobsCreated = 0;

        // calculate the number of jobs created by each local business
        for (String businessName : localBusinesses.keySet()) {
            int jobsCreated = (int) (localBusinesses.get(businessName) / avgProfits);
            totalJobsCreated += jobsCreated;
            System.out.println(businessName + " created " + jobsCreated + " jobs.");
        }        

        // print the total number of jobs created by the local businesses
        System.out.println("Total jobs created by local businesses: " + totalJobsCreated);

        // create a variable that will store the money invested in local businesses
        double moneyInvested = 0.0;

        // calculate the amount of money invested in each business
        for (String businessName : localBusinesses.keySet()) {
            moneyInvested += localBusinesses.get(businessName) * 0.1;
            System.out.println("Ten percent of " + businessName + "'s profits invested back into the business: " + (localBusinesses.get(businessName) * 0.1));
        }

        // print the total amount of money invested in local businesses
        System.out.println("Total money invested in local businesses: " + moneyInvested);

        // calculate the total amount of money invested in the local economy
        double totalMoneyInvested = moneyInvested + totalProfits;

        // print the total amount of money invested in the local economy
        System.out.println("Total money invested in the local economy: " + totalMoneyInvested);

        // create a program to promote entrepreneurship
        System.out.println("Creating a program to promote entrepreneurship...");
        System.out.println("Offering low-interest loans to local businesses...");
        System.out.println("Providing mentorship and training for entrepreneurs...");
        System.out.println("Encouraging businesses to invest in the community...");
        System.out.println("Supporting local business innovation and growth...");

        // print a success message
        System.out.println("Success! A community economic development project has been created to support local businesses and promote entrepreneurship, fostering a thriving local economy.");
    }

}
package sem4;

public class Task1 {
    public interface Message {
        void send();
    }

    public static class EmailMessage implements Message {
        @Override
        public void send() {
            System.out.println("sending email...");
        }
    }

    public static class SMSMessage implements Message {
        @Override
        public void send() {
            System.out.println("sending sms...");
        }
    }

    public static class PushNotification implements Message {
        @Override
        public void send() {
            System.out.println("sending push notification...");
        }
    }

    public static class MessageFactory {
        public static Message createMessage(String type) {
            switch (type.toLowerCase()) {
                case "email":
                    return new EmailMessage();
                case "sms":
                    return new SMSMessage();
                case "push":
                    return new PushNotification();
                default:
                    throw new IllegalArgumentException("Invalid message type: " + type);
            }
        }
    }

    public static void main(String[] args) {
        Message email = MessageFactory.createMessage("email");
        email.send();

        Message sms = MessageFactory.createMessage("sms");
        sms.send();

        Message push = MessageFactory.createMessage("push");
        push.send();
    }
}

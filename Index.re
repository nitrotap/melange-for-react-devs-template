
module App = {
  [@react.component]
  let make = () => {
    // Wrap elements in a single parent div to ensure valid JSX
    <div>
      <h1> {React.string("Welcome to my app!")} </h1>
      <Chatbot
        message="Hello! I'm your chatbot."
        onSend={(input: string) => Js.log("User said: " ++ input)}
      />
    </div>
  };
};

let node = ReactDOM.querySelector("#root");
switch (node) {
| None =>
  Js.Console.error("Failed to start React: couldn't find the #root element")
| Some(root) =>
  let root = ReactDOM.Client.createRoot(root);
  root->ReactDOM.Client.render(<App />);
};

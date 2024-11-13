[@react.component]
let make = (~message: string, ~onSend: string => string) => {
  let (prompt, setPrompt) = React.useState(() => "");
  let (chatHistory, setChatHistory) = React.useState(() => []);

  let handleChange = (event: React.Event.Form.t) => {
    let newValue = React.Event.Form.target(event)##value;
    setPrompt(_ => newValue);
  };

  let handleSend = (_event: React.Event.Mouse.t) => {
    if (prompt != "") {
      let botResponse = onSend(prompt);
      setChatHistory(history => [("user", prompt), ("bot", botResponse)] @ history);
      setPrompt(_ => "");
    };
  };


  let listToArray = list =>
  Array.init(List.length(list), idx => List.nth(list, idx));


  <div>
    {React.string(message)}
    <div>
      {React.array(
        chatHistory
        |> listToArray
        |> Array.mapi((index, (sender, content)) =>
              <div key={string_of_int(index)}>
                <strong>{React.string(sender ++ ": ")}</strong>
                {React.string(content)}
              </div>
            )
          )}
    </div>

    <input
      type_="text"
      value=prompt
      onChange={handleChange}
      placeholder="Enter your prompt"
    />
    <button onClick={handleSend}>
      {React.string("Send")}
    </button>
    <button onClick={_ => setChatHistory(_ => [])}>
      {React.string("Clear Chat")}
    </button>
  </div>;
};

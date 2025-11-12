template <typename Hdl> class BackAwaiter {
  Hdl hdl =
      nullptr; // coroutine handle saved from await_suspend() for await_resume()
public:
  BackAwaiter() = default;

  bool await_ready() const noexcept {
    return false; // do suspend
  }

  void await_suspend(Hdl h) noexcept {
    hdl = h; // save handle to get access to its promise
  }

  auto await_resume() const noexcept {
    return hdl.promise().backValue; // return back value stored in the promise
  }
};
